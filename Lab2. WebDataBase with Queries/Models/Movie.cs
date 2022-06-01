using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class Movie
    {
        public Movie()
        {
            ActorsInMovies = new HashSet<ActorsInMovie>();
            DirectorMovies = new HashSet<DirectorMovie>();
            MoviesGenres = new HashSet<MoviesGenre>();
        }

        public int Id { get; set; }

        [Display(Name = "Назва фільму")]
        [Required(ErrorMessage = "Поле не повинно бути порожнім")]
        public string Name { get; set; } = null!;

        [Display(Name = "Тривалість фільму (у хв)")]
        [Required(ErrorMessage = "Поле не повинно бути порожнім")]
        [Range(1, Int32.MaxValue)]
        public int Duration { get; set; }

        [Display(Name = "Кіностудія")]
        [Required(ErrorMessage = "Поле не повинно бути порожнім")]
        public int ProductionId { get; set; }

        [Display(Name = "Рейтинг IMDb")]
        [DisplayFormat(DataFormatString = @"{0:F2}", HtmlEncode = false, ApplyFormatInEditMode = true)]
        [Required(ErrorMessage = "Поле не повинно бути порожнім")]
        [Range(0d, 10d)]
        public double ImdbRate { get; set; }

        [Display(Name = "Рік випуску")]
        [Required(ErrorMessage = "Поле не повинно бути порожнім")]
        public int ProdYear { get; set; }

        [Display(Name = "Кіностудія")]
        public virtual Production? Production { get; set; } = null!;

        [Display(Name = "Актори")]
        public virtual ICollection<ActorsInMovie>? ActorsInMovies { get; set; }
        [Display(Name = "Режисер")]
        public virtual ICollection<DirectorMovie>? DirectorMovies { get; set; }
        [Display(Name = "Жанри")]
        public virtual ICollection<MoviesGenre>? MoviesGenres { get; set; }
    }
}
